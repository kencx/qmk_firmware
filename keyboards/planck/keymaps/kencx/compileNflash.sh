#!/bin/bash

set -euo pipefail

cd "$HOME/dev/qmk/qmk_firmware" &&
    util/docker_build.sh planck/rev6:kennethcheo

qmk flash -kb planck/rev6 -km kennethcheo
