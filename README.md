firstboot-qt
------------
[NOT](https://github.com/systemd/systemd/issues/3401) systemd-firstboot Qt frontend.


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

