#!/bin/bash

set -euo pipefail

cd "$HOME/dev/qmk_firmware" &&
    util/docker_build.sh planck/rev6:kencx

cd "$HOME/dev/qmk_firmware" && util/docker_build.sh qmk setup
cd "$HOME/dev/qmk_firmware" && util/docker_cmd.sh qmk flash -kb planck/rev6 -km kencx
