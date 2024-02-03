if ps -p $1 > /dev/null
then
pid="$1"

while [ $pid != "0" ]
do
./os_0007.sh $pid $2
pid=`ps -o ppid= -p $pid`
done

else
echo no parameters found
fi