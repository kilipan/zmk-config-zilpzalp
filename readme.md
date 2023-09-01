![zilpzalp](https://github.com/kilipan/zilpzalp/blob/main/img/zilpzalp_photo.jpg?raw=true)

# zilpzalp ZMK firmware

_A wonky 28-key split-unibody column-stagger keyboard._

[Here](https://github.com/kilipan/zilpzalp) you can find the hardware files.\
[Here](https://github.com/kilipan/qmk-config-zilpzalp) you can find the QMK config for zilpzalp.

## HOW TO USE

- fork this repo
- `git clone` your repo, to create a local copy on your PC (you can use the [command line](https://www.atlassian.com/git/tutorials) or [github desktop](https://desktop.github.com/))
- adjust the zilpzalp.keymap file (find all the keycodes on [the zmk docs pages](https://zmk.dev/docs/codes/))
- `git push` your repo to your fork
- on the GitHub page of your fork navigate to "Actions"
- scroll down and unzip the `firmware.zip` archive that contains the latest firmware
- connect the zilpzalp to your PC, press reset and hold the boot key during reset
- the keyboard should now appear as a mass storage device
- drag'n'drop the `zilpzalp-seeeduino_xiao_ble-zmk.uf2` file from the archive onto the storage device

## Troubeshooting

On macOs you might get an error stating that the `operation can’t be completed unexpected error 100093`. You can circumvent this by copying the file from your terminal:

- move the `zilpzalp-seeeduino_xiao_ble-zmk.uf2` to your root directory
- copy the file onto the zilpzalp volume: `cp -X zilpzalp-seeeduino_xiao_ble-zmk.uf2 ../../Volumes/<volume_name>/`
