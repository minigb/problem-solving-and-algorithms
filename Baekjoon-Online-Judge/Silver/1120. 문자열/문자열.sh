read s1 s2

s1Len=${#s1}
s2Len=${#s2}

if [ $s1Len -gt $s2Len ]; then
        tmp=$s1
        s1=$s2
        s2=$tmp

        s1Len=${#s1}
        s2Len=${#s2}
fi

ans=9999
s2Start=0

while [ $(($s2Start + $s1Len - 1)) -lt $s2Len ]; do
        i=0
        j=$s2Start
        count=0
        while [ $i -lt $s1Len ] && [ $j -lt $s2Len ]; do
                c1=${s1:$i:1}
                c2=${s2:$j:1}
                if [ $c1 != $c2 ]; then
                        count=$(($count+1))
                fi
                        i=$(($i+1))
                j=$(($j+1))
        done
        if [ $ans -gt $count ]; then
                ans=$count
        fi
        s2Start=$(($s2Start + 1))
done

echo $ans