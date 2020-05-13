#!/bin/bash

set -e

sudo apt-get install cppcheck 

[[ ! -f .cppcheckignore ]] || CPPCHECK_OPTIONS="${CPPCHECK_OPTIONS} --verbose --suppressions-list=.cppcheckignore"
	
cppcheck --force --error-exitcode=1 $CPPCHECK_OPTIONS .
