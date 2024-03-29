#!/bin/bash

MAKEFILE_PATH="Makefile"
SRC_DIR="src"

function insert_at_line()
{
	sed -i "${cursor}i ${1}" ${MAKEFILE_PATH}
	let "cursor=cursor+1"
}

function insert_at_line_with_tab()
{
	sed -i "${cursor}i ${file}" ${MAKEFILE_PATH}
	sed -i "s|^${file}|\t\t\t\t   ${file} \\\\|" ${MAKEFILE_PATH}
	let "cursor=cursor+1"
}

function append_to_variable_src()
{
	sed -i "s|SRC_C			:=|SRC_C			:= ${1} \\\\|" ${MAKEFILE_PATH}
	is_first=1
}

function clean_source_makefile()
{
	begin_src=$(grep -nE "^SRC_C\s*:=" ${MAKEFILE_PATH})
	begin_src=${begin_src/:*/}
	cursor=${begin_src}
	sed -i "${cursor}d" ${MAKEFILE_PATH}
	end_src=$(grep -nE '^\s*.*[0-9a-zA-Z]\.c$' ${MAKEFILE_PATH})
	end_src=${end_src/:*/}
	sed -i "${begin_src},${end_src}d" ${MAKEFILE_PATH}
	insert_at_line "SRC_C			:="
}

function remove_last_backslash()
{
	let "cursor=cursor-1"
	last_src_line=$(sed -n "${cursor}p" ${MAKEFILE_PATH})
	last_src_line=$(echo ${last_src_line} | tr -d '\\' | tr -d ' ' | tr -d '\t')
	sed -i "${cursor}d" ${MAKEFILE_PATH}
	sed -i "${cursor}i ${last_src_line}" ${MAKEFILE_PATH}
	sed -i "s|^${last_src_line}|\t\t\t\t   ${last_src_line}|" ${MAKEFILE_PATH}
}

function main()
{
	is_first=0
	clean_source_makefile
	for file in $(find ${SRC_DIR} -type f -name "*.c")
	do
		if [ ${is_first} == 0 ]
		then
			append_to_variable_src ${file}
		else
			insert_at_line_with_tab ${file}
		fi
	done
	remove_last_backslash
}

main
