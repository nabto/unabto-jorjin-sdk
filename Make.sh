

#!/bin/bash
# This script clears the terminal, displays a greeting and copies the
# relevant files from the uNabto submodule. It then deletes the remaining files.

clear				# clear terminal window

echo "The script starts now."

cp unabto/src/unabto/. src/unabto/ -R

mkdir -p src/modules/crypto/generic/

mkdir -p src/platforms/

cp unabto/src/modules/crypto/generic/. src/modules/crypto/generic/ -R

cp unabto/src/platforms/unabto_common_types.h src/platforms/unabto_common_types.h -R

rm -rf unabto

echo "I'm giving you back your prompt now."
echo