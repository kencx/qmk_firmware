#!/bin/bash

set -euo pipefail

cd "$HOME/dev/qmk_firmware" &&
    util/docker_build.sh planck/rev6:kencx

qmk flash -kb planck/rev6 -km kencx
