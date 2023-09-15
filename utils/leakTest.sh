# Leak test every second

PROGRAM=

while :
do
	leaks $PROGRAM
	sleep 1
done
