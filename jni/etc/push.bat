rem adb push libprotobuf.so /system/lib/

rem adb shell "stop facedis"
rem adb shell "rm /system/bin/facedis"

adb push pbjson_test /system/bin/pbjson_test
adb shell chmod 777 /system/bin/pbjson_test
adb shell "/system/bin/pbjson_test"