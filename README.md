# Glover Decompilation
A decompilation of the n64 version of Glover</br>
Special thanks to Piko Interactive. Check out their [bleem.net](https://www.bleem.net/) project here

# Building
- Clone the repo with `git clone https://github.com/Rainchus/Glover`
- Run `pip install -r requirements.txt` to install the dependencies
- Obtain your own copy of the rom, and place it in the root of the project named `baserom.us.z64`
- Run `make setup` to extract information from the rom
- Run `make -j` to build with changes