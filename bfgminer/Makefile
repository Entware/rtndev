#
# Copyright (C) 2011-2016 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=bfgminer
PKG_VERSION:=5.4.2
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).txz
PKG_SOURCE_URL:=http://luke.dashjr.org/programs/bitcoin/files/$(PKG_NAME)/$(PKG_VERSION)
PKG_MD5SUM:=756daab8d1d9da47c984ed49f9c9a8c8

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Download/uthash
	FILE:=v1.9.8
	URL:=https://codeload.github.com/troydhanson/uthash/tar.gz/
endef
$(eval $(call Download,uthash))

define Package/bfgminer
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS=+jansson +libcurl +libevent2 +libncurses +libusb-1.0 +libudev
	TITLE:=modular ASIC/FPGA Bitcoin miner
	URL:=http://bfgminer.org/
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/bfgminer/description
 Modular Bitcoin ASIC/FPGA/GPU/CPU miner in C.
endef

define Build/Prepare
	$(call Build/Prepare/Default)
	gzip -dc $(DL_DIR)/v1.9.8 | $(HOST_TAR) -C $(PKG_BUILD_DIR) $(TAR_OPTIONS)
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

TARGET_CFLAGS += \
	-std=gnu99 \
	-Iuthash-1.9.8/src

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
