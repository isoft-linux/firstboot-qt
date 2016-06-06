firstboot-qt
------------
Just like [systemd-firstboot](https://www.freedesktop.org/software/systemd/man/systemd-firstboot.html) but [provided](https://github.com/systemd/systemd/issues/3401) Qt frontend.


## Build && Install

```
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr \
    -DKDE_INSTALL_USE_QT_SYS_PATHS=ON \
    -DENABLE_DEBUG=ON
make
sudo make install
```

