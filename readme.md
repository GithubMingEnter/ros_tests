


## Run
```bash
catkin_make run_tests
```
then
```bash
[ROSTEST]-----------------------------------------------------------------------

[testing.rosunit-Unit-Tests/lowValue][passed]
[testing.rosunit-Unit-Tests/highValue][passed]

SUMMARY
 * RESULT: SUCCESS
 * TESTS: 2
 * ERRORS: 0
 * FAILURES: 0

rostest log file is in /home/d/.ros/log/rostest-d-2032417.log
```

改变函数判断50改为其他值，如60，

```c++
int Talker::doSomeMath(int value) {
    int next_value = 0;
    next_value = 5 + value;
    return next_value > 60 ? 0 : next_value;
}
```
可以看到失败


``` bash
[ROSTEST]-----------------------------------------------------------------------

[testing.rosunit-Unit-Tests/lowValue][FAILURE]----------------------------------
/home/d/test/test_ws/src/ros_gtest/tests/tests_1.cpp:23
Expected equality of these values:
  value
    Which is: 0
  initial_value+5
    Which is: 8
Value should be it's initial value plus 5
--------------------------------------------------------------------------------

[testing.rosunit-Unit-Tests/highValue][passed]

SUMMARY
 * RESULT: FAIL
 * TESTS: 2
 * ERRORS: 0
 * FAILURES: 1
```

```bash
$ source devel/setup.bash
$ rosrun testing talker_node
[ INFO] [1689599598.095641123]: I'm talking 3
```
## ref
https://www.youtube.com/watch?v=urdeAo3lr_I