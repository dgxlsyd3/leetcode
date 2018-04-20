# Read from the file file.txt and output the tenth line to stdout.
# 怎么只打印一个文件中的第十行？
i=1
while read line
do
    if [ $i -eq 10 ] ; then
        echo $line
    fi
    i=$((i+1))
done < file.txt
