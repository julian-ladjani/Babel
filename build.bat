if exist "build" (
rmdir /s /q build)
if not exist "build" (
mkdir "build")
cd build
conan install .. --build missing
conan build ..
cd ..
