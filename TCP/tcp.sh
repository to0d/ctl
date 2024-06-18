#!/bin/bash
#####################################################
script_abs=$(readlink -f "$0")
script_dir=$(dirname $script_abs)
workspace=$script_dir


#####################################################
#           main routine
#   
#####################################################

usage()
{
    echo "-l    list"
    echo "-m    make"
    echo "-r    run"
    echo "-c    clean"
    echo "-n    testcase"
    echo "-t    type"
    echo "-p    prime"
}

lt_action_list=0
lt_action_make=0
lt_action_run=0
lt_action_clean=0
lt_count=0

test_des=""
test_level=-1
test_type=""
test_prime=0
test_dir_list=""
test_name_select=""
test_type_select=""
test_level_select=-1

if [ $# -eq 0 ]; then
  lt_action_list=1
  lt_action_clean=1
  lt_action_make=1
  lt_action_run=1
  lt_count=4
else
  while getopts 't:n:lL:rmcph' OPTION
  do
    case $OPTION in
    l)  lt_action_list=1
        lt_count=`expr $lt_count + 1`
        ;;
    L)  test_level_select=`expr $OPTARG`
        ;;
    r)  lt_action_run=1
        lt_count=`expr $lt_count + 1`
        ;;
    m)  lt_action_make=1
        lt_count=`expr $lt_count + 1`
        ;;
    n)  test_name_select=$OPTARG
        ;;
    t)  test_type_select=$OPTARG
        ;;
    c)  lt_action_clean=1
        lt_count=`expr $lt_count + 1`
        ;;
    p)  test_prime=1
        ;;
    h)  usage
        exit 0
        ;; 
    \?) echo "lt error: unknown parameter '$OPTION'"
        usage
        exit 1
        ;;
    esac
  done
fi



update_test_des(){

  if [ ! -e "makefile" ]; then
    test_des=""
    test_type=""
  else    
    test_des=`cat makefile | grep '#TEST: '| awk -F : '{print $2}'`
    test_type=`echo $test_des | awk '{print $3}'`
    
    if [[ $test_des =~ Level[[:space:]]+([0-9]+) ]]; then
      level_number=${BASH_REMATCH[1]}
      test_level=`expr $level_number`
    else
      test_level=-1
  fi

  #echo $test_type
  fi
}

update_test_dir_list(){
  test_dir_list=$(find $workspace -mindepth 1 -type d | grep -v -e "\.$" | sort)
}


if [ $lt_count == 0 ]; then
  echo "lt error: not action specified"
  exit 1
fi

if [ $lt_action_list == 1 ]; then

  update_test_dir_list          
  for testcase_dir in $test_dir_list
  {
    cd $testcase_dir
    update_test_des
    if [ -z $test_type ]; then
      continue
    fi
    
    if [ ! -z "$test_type_select" -a "$test_type_select" != "$test_type" ]; then
      continue
    fi
    
    test_name=`basename $testcase_dir`
    if [ ! -z "$test_name_select" -a "$test_name_select" != "$test_name" ]; then
      continue
    fi
    
    if [ $test_level_select != -1 -a "$test_level_select" != "$test_level" ]; then
      continue
    fi
    
    printf  "found %-10s: " $test_name     
    echo $test_des
  }
fi

lt_succ=0
lt_total=0

if [ $lt_action_clean == 1 ]; then

  lt_succ=0
  lt_total=0
   
  update_test_dir_list          
  for testcase_dir in $test_dir_list
  {
    cd $testcase_dir
    update_test_des
    if [ -z $test_type ]; then
      continue
    fi
    
    if [ ! -z "$test_type_select" -a "$test_type_select" != "$test_type" ]; then
      continue
    fi
    
    test_name=`basename $testcase_dir`
    if [ ! -z "$test_name_select" -a "$test_name_select" != "$test_name" ]; then
      continue
    fi
    
    if [ $test_level_select != -1 -a "$test_level_select" != "$test_level" ]; then
      continue
    fi

    printf  "clean %-10s: " $test_name 
    lt_total=`expr $lt_total + 1`
    
    make clean > /dev/null 2>&1
    
    if [ $? -ne 0 ] ; then
      echo "fail"
    else
      echo "succ"
      lt_succ=`expr $lt_succ + 1`
    fi
  }
  
  echo "total "$lt_total", succ "$lt_succ
fi

testcase_make_result="make_result"

if [ $lt_action_make == 1 ]; then

  lt_succ=0
  lt_total=0

  update_test_dir_list          
  for testcase_dir in $test_dir_list
  {        
    cd $testcase_dir
    
    update_test_des
    if [ -z $test_type ]; then
      continue
    fi
    
    if [ ! -z "$test_type_select" -a "$test_type_select" != "$test_type" ]; then
      continue
    fi

    test_name=`basename $testcase_dir`
    if [ ! -z "$test_name_select" -a "$test_name_select" != "$test_name" ]; then
      continue
    fi
    
    if [ $test_level_select != -1 -a "$test_level_select" != "$test_level" ]; then
      continue
    fi

    printf  "make %-10s: " $test_name

    lt_total=`expr $lt_total + 1`
    
    make > $testcase_make_result 2>&1

    if [ $? -ne 0 ] ; then
      echo "fail"
      cat $testcase_make_result
    else
      echo "succ"
      lt_succ=`expr $lt_succ + 1`
    fi
    
    rm -rf $testcase_make_result
  }
  
  echo "total "$lt_total", succ "$lt_succ
fi

testcase_name=""
output_file=""
expect_file=""
diff_result="diff_result"

run_diff(){

  # test mode
  if [ $test_prime -eq 0 ] ; then
    diff --strip-trailing-cr $output_file $expect_file > $diff_result 2>&1
    if [ $? -ne 0 ] ; then
      echo "fail"
      printf  "  %-8s: " "Test" 
      echo $test_des
      printf  "  %-8s: %s\n" "Result" "diff "$testcase_name"/"$output_file" "$testcase_name"/"$expect_file 
      head -5 $diff_result | awk '{print "            "$0}'
    else
      echo "succ"
      lt_succ=`expr $lt_succ + 1`
    fi
    rm -rf $diff_result
  
  # prime mode
  else
    cat $output_file > $expect_file
    echo "prime"
    lt_succ=`expr $lt_succ + 1`
  fi
}

if [ $lt_action_run == 1 ]; then

  lt_succ=0
  lt_total=0
  
  export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../../build

  update_test_dir_list          
  for testcase_dir in $test_dir_list
  {
    cd $testcase_dir
    
    update_test_des
    if [ -z $test_type ]; then
      continue
    fi
    
    if [ ! -z "$test_type_select" -a "$test_type_select" != "$test_type" ]; then
      continue
    fi
    
    test_name=`basename $testcase_dir`
    if [ ! -z "$test_name_select" -a "$test_name_select" != "$test_name" ]; then
      continue
    fi
    
    if [ $test_level_select != -1 -a "$test_level_select" != "$test_level" ]; then
      continue
    fi
    
    printf  "run %-10s: " $test_name  
    lt_total=`expr $lt_total + 1`
    
    # ********************************************* #
    # compile & run testcase
    # ********************************************* #
    if [ $test_type == "Compile_" ]; then
        
      should_fail_des=`cat makefile | grep "SHOULD-FAIL" | wc -l`
      
      # 'SHOULD-FAIL' means the compile should fail
      # Only need check trace.txt
      if [ $should_fail_des == "1" ]; then

        CMD=`cat makefile  | grep scc | awk -F \# '{print $2}'`
        $CMD > trace.txt 2>&1
        
        # the previous should fail
        if [ $? -eq 0 ] ; then
          echo "fail"
          printf  "  %-8s: %s" "Test"
          echo $test_des
          printf  "  %-8s: %s\n" "Expect" "The command should fail"
          printf  "  %-8s: %s\n" "Cmd" $CMD
          exit 1
        else
          output_file="trace.txt"
          expect_file="expect.txt"
          run_diff
        fi

      else
        if [ ! -e "a.out" ]; then
          echo "error, a.out not found"
        else
          ./a.out 1> result.txt
          output_file="result.txt"
          expect_file="expect.txt"
          run_diff
        fi
      fi

      continue;
    fi
    
    # ********************************************* #
    # transfer testcase
    # ********************************************* #
    if [ $test_type == "Transfer" ]; then
    
      input_file=`ls | grep "input.*" | grep -v tmp | grep -v ".ll" | grep -v ".expand."`            

      if [ -z $input_file ]; then
        echo "error, input file not found"

      else
      
        no_need_des=`cat makefile | grep "NO-NEED" | wc -l`
        src_suffix=`echo "${input_file##*.}"`
        
        output_file="output."$src_suffix
        expect_file="expect."$src_suffix
        
        # 'NO-NEED' means this file is no-neeed to be transfered
        # Thus, no output file will be created 
        if [ $no_need_des == "1" ]; then
          if [ -e $output_file ]; then
            echo "fail"
            printf  "  %-8s: " "Test"
            echo $test_des
            printf  "  %-8s: %s\n" "Result" "output should not be generated"
          else
            echo "succ"
            lt_succ=`expr $lt_succ + 1`
          fi
        else
          run_diff
        fi
      fi

      continue;
    fi
    
    # ********************************************* #
    # Optimize testcase
    # ********************************************* #
    if [ $test_type == "Optimize" ]; then
    
      #input_file=`ls | grep "input.*" | grep -v tmp | grep -v ".ll" | grep -v ".expand."`            
      if [ -z output.ll ]; then
        echo "error, input file not found"
      else
        cat output.ll | grep -v ModuleID | grep -v source_filename | grep -v "clang version" > output2.ll
        output_file="output2.ll"
        expect_file="expect.ll"
        run_diff
        rm -rf output2.ll
      fi

      continue;
    fi

    # ********************************************* #
    # unit test testcase
    # ********************************************* #
    if [ $test_type == "Unittest" ]; then

      ./test.sh 2>&1 | grep -v "\[trac2\]"  > result.txt

      output_file="result.txt"
      expect_file="expect.txt"
      run_diff

      continue;
    fi       

    echo "unkown: test_type="$test_type
  }

  echo "total "$lt_total", succ "$lt_succ
fi

