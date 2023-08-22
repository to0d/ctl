#!/bin/sh
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
    echo "-l list"
    echo "-m make"
    echo "-c clean"
    echo "-r run"
}

if [ $# -eq 0 ]; then
    echo "tc error: no args specified."
    usage
    exit 1
fi

lt_type=sh
lt_action_list=0
lt_action_make=0
lt_action_run=0
lt_action_clean=0

lt_count=0

while getopts 'lmcrh' OPTION
do
    case $OPTION in
    l)  lt_action_list=1
        lt_count=`expr $lt_count + 1`
        ;;
    m)  lt_action_make=1
        lt_count=`expr $lt_count + 1`
        ;;
    r)  lt_action_run=1
        lt_count=`expr $lt_count + 1`
        ;;
    c)  lt_action_clean=1
        lt_count=`expr $lt_count + 1`
        ;;
    h)  usage
        exit 0
        ;; 
    \?) echo "tc error: unknown parameter '$OPTION'"
        usage
        exit 1
        ;;
    esac
done

if [ $lt_count == 0 ]; then
    echo "tcpp error: not action specified"
    exit 1
fi

if [ $lt_action_list == 1 ]; then
    
    test_dir_list=$(find $workspace -type d| grep -v -e "\.$")
   
    for pt_dir in $test_dir_list
    {
        # query test
        test_sh_list=$(ls $pt_dir | grep -e "^TC.*\.${lt_type}$")
        for pt_name in $test_sh_list
        {   pt_sh=$pt_dir/$pt_name    
            echo $pt_dir/$pt_name 
        }
    }

fi

if [ $lt_action_make == 1 ]; then

    test_dir_list=$(find $workspace -type d| grep -v -e "\.$")
    for pt_dir in $test_dir_list
    {    
        # query test
        test_sh_list=$(ls $pt_dir | grep -e "^TC.*\.${lt_type}$")
        if [ ! "$test_sh_list" = "" ]
        then
            cd $pt_dir
            pwd
            make
        fi
    }

fi

if [ $lt_action_run == 1 ]; then

    out_file=$workspace/$lt_type.out

    if [ -f $out_file ]
    then
        rm $out_file
    fi

    test_dir_list=$(find . -type d | grep -v -e "\.$")
    for pt_dir in $test_dir_list
    {   
        cd $workspace
         
        # query test
        test_sh_list=$(ls $pt_dir | grep -e "^TC.*\.${lt_type}$")
        if [ ! "$test_sh_list" = "" ]
        then   
            cd $pt_dir   
            pt_sh=$pt_dir.sh
            pt_out=$pt_sh".out"        
            printf  "%s: " $pt_dir | tee -a $out_file 
            ./$pt_sh > $pt_out 2>&1
            if [ -f $pt_out ]
            then
                pt_summary=`cat $pt_out | grep -i "output"`
                echo $pt_summary | tee -a $out_file 
            else
                echo "error, result not found!" | tee -a $out_file 
            fi
        fi
    }

fi

if [ $lt_action_clean == 1 ]; then
        
    test_dir_list=$(find $workspace -type d| grep -v -e "\.$")
    for pt_dir in $test_dir_list
    {    
        # query test
        test_sh_list=$(ls $pt_dir | grep -e "^TC.*\.${lt_type}$")
        if [ ! "$test_sh_list" = "" ]
        then
            cd $pt_dir
            pwd
            make clean
        fi
    }

fi
