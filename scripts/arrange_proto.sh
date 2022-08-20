#!/bin/bash

SRC_DIR="src"
INC_FILE="includes/pipex.h"

while [ "$1" != "" ]
do
	case $1 in
		-R)
			REPLACE=1
			;;
	esac
	shift
done

function insert_at_line()
{
	sed -i "${cursor}i ${1}" ${INC_FILE}
	let "cursor=cursor+1"
}

function clear_header()
{
	begin=$(grep -n '/\* FILES \*/' ${INC_FILE})
	cursor=${begin/:*/}
	sed -i '/\/\* FILES \*\//,/\/\* ############*/d' ${INC_FILE}
	#begin=$(echo "${begin} 2 +p" | dc)
	insert_at_line '/* FILES */'
	insert_at_line '/* ##### */'
	insert_at_line '\\'
}

function get_function_in_file()
{
	tmp_func=$(sed -nE 's|^[a-z0-9A-Z\_]+\s(\**?[a-z0-9A-Z\_]*)\(.*|\1|p' ${1} | \
			   grep -vE '^static')
	insert_at_line "// ${file/*\//}"
	for func in ${tmp_func}
	do
		tmp1000=$(echo ${func} | sed 's|\*|\\\*|')
		insert_at_line "$(grep -E "^[a-z0-9A-Z\_]+\s${tmp1000}\(.*\)$" ${file});"
	done
	insert_at_line '\\'
}

function main ()
{
	clear_header
	ALL_C_FILE=$(find $(realpath ${SRC_DIR}) -name "*.c" | sort -n)
	for file in ${ALL_C_FILE}
	do
		get_function_in_file ${file}
	done
	insert_at_line "/* ########################################################################## */"
}

main
