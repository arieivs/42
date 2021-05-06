if [ "$1" = 'off' ]; then
	sed 's/
	$CURR = 'autoindex on'
	$NEW = 'autoindex off'
else
	$CURR = 'autoindex off'
	$NEW = 'autoindex on'
fi

sed 's/$
