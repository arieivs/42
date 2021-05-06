#!/bin/bash

if [ "$1" = 'off' ]; then
	sed -i "s/autoindex on/autoindex off/g" /etc/nginx/sites-available/default
elif [ "$1" = 'on' ]; then
	sed -i "s/autoindex off/autoindex on/g" /etc/nginx/sites-available/default
fi

service nginx reload
