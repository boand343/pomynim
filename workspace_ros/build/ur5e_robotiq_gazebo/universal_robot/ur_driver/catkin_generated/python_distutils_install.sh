#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/boand/workspace_ros/src/ur5e_robotiq_gazebo/universal_robot/ur_driver"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/boand/workspace_ros/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/boand/workspace_ros/install/lib/python2.7/dist-packages:/home/boand/workspace_ros/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/boand/workspace_ros/build" \
    "/usr/bin/python2" \
    "/home/boand/workspace_ros/src/ur5e_robotiq_gazebo/universal_robot/ur_driver/setup.py" \
    build --build-base "/home/boand/workspace_ros/build/ur5e_robotiq_gazebo/universal_robot/ur_driver" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/boand/workspace_ros/install" --install-scripts="/home/boand/workspace_ros/install/bin"
