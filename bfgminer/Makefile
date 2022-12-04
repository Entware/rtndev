#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=bfgminer
PKG_VERSION:=5.5.0
PKG_RELEASE:=3

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).zip
PKG_SOURCE_URL:=http://bfgminer.org/files/$(PKG_VERSION)
PKG_HASH:=67e716b04e0bebb311d6e805e1e1fbabca2187a7d9fb05e38e1f8447d6cb72ac

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Download/uthash
	FILE:=v2.1.0
	URL:=https://codeload.github.com/troydhanson/uthash/tar.gz/
	HASH:=152ccd8e64d0f495377232e3964d06c7ec8bb8c3fbd3217f8a5702614f9a669e
endef
$(eval $(call Download,uthash))

define Package/bfgminer
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS=+jansson +libcurl +libevent2 +libncurses +libusb-1.0 +USE_GLIBC:libudev \
		+libevent2-pthreads
	TITLE:=modular ASIC/FPGA Bitcoin miner
	URL:=http://bfgminer.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/bfgminer/description
 Modular Bitcoin ASIC/FPGA/GPU/CPU miner in C.
endef

define Build/Prepare
	$(call Build/Prepare/Default)
	gzip -dc $(DL_DIR)/v2.1.0 | $(HOST_TAR) -C $(PKG_BUILD_DIR) $(TAR_OPTIONS)
endef

CONFIGURE_ARGS += \
	--enable-keccak \
	--enable-scrypt \
	--enable-cpumining \
	--without-uio \
	--without-vfio \
	--without-sensors \
	--without-libmicrohttpd \
	--with-curses=ncurses \
	--without-system-libbase58 \
	--without-libudev

TARGET_CFLAGS += \
	-std=gnu99 \
	-Iuthash-2.1.0/src \
	-DJSON_INTEGER_IS_LONG_LONG

define Build/Configure
	chmod +x $(PKG_BUILD_DIR)/configure
	chmod +x $(PKG_BUILD_DIR)/gen-version.sh
	$(call Build/Configure/Default)
endef

define Package/bfgminer/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/bfgminer{,-rpc} $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) \
	    $(PKG_INSTALL_DIR)/opt/lib/libbase58.so* \
	    $(PKG_INSTALL_DIR)/opt/lib/libblkmaker-0.1.so* \
	    $(PKG_INSTALL_DIR)/opt/lib/libblkmaker_jansson-0.1.so* \
	    $(1)/opt/lib
endef

$(eval $(call BuildPackage,bfgminer))
