max=50
c=0
rm traceresult
for i in `seq 2 $max`
do
	./filler_vm -p1 $1 -p2 $2 -f $3 > result
	cat filler.trace >> traceresult 
done
cat traceresult | grep "$1" | wc -l > result1
cat traceresult | grep "$2" | wc -l > result2
echo "$1 wins"
cat result1
echo "sur $max"
