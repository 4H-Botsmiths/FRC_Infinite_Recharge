paths=(
	"C:\\Users\\ByteByByte\\vsc\\InfiniteRecharge\\config.dat"
)

echo "Choose a file to push:"

for i in "${!paths[@]}"
do
	echo "[$i] ${paths[$i]}"
done

echo -n "> "
read filen

cat << EOL > "/c/Users/ByteByByte/send.txt"
anonymous
cd /home/lvuser/
put ${paths[$filen]}
bye
EOL

ftp -s:/c/Users/ByteByByte/send.txt 10.43.9.2
#ftp -s:/c/Users/ByteByByte/send.txt 169.254.33.199
rm /c/Users/ByteByByte/send.txt

read