#!/bin/sh

LLVM_PATH=~/llvm-project

commit_count=0

cd $LLVM_PATH

rm -f riscv_sources.txt
rm -f riscv_commits.txt
rm -f riscv_total.txt

commit_list=$(git log --before="2018-12-12" --grep="riscv" -i | grep -e "^commit" | awk '{print $2}' | tac)
for commit in $commit_list
{
    echo "check: " $commit
    git show $commit > _tmp1.txt
    title=$(cat _tmp1.txt | grep -e "\[RISCV\]" -e "\[riscv\]" -e "\[RISC-V\]" -e "\[risc-v\]")
    if [ ! "$title" = "" ] 
    then
        git show $commit | grep "+++ b" | cut -b 7- > _tmp1.txt
        source_count=$(cat _tmp1.txt | wc -l)
        echo "title: "$title", source: "$source_count 
        cat _tmp1.txt >> _tmp2.txt
        commit_count=`expr $commit_count + 1`
        echo $commit >> riscv_commits.txt
        echo "commit: "$commit >> riscv_total.txt
        echo "title: "$title >> riscv_total.txt
        cat _tmp1.txt >> riscv_total.txt
        echo "" >> riscv_total.txt
    fi
}

cat _tmp2.txt | sort | uniq | grep -v "/test/" | grep -v "unittests" >> riscv_sources.txt
total_source_count=$(cat riscv_sources.txt | wc -l)
echo "done: "$commit_count" commits, "$total_source_count" sources"

rm -f _tmp1.txt
rm -f _tmp2.txt