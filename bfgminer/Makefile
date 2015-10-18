#
# Copyright 2013 Luke Dashjr
# Copyright (C) 2013 - 2015 Entware
#
# This program is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the Free
# Software Foundation; either version 3 of the License, or (at your option)
# any later version.  See COPYING for more details.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=bfgminer
PKG_TITLE:=BFGMiner
PKG_VERSION:=5.2.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).zip
PKG_SOURCE_URL:=http://luke.dashjr.org/programs/bitcoin/files/$(PKG_NAME)/$(PKG_VERSION)
PKG_MD5SUM:=b9caca01226a38018766c4894e5f31d7

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Download/uthash
	FILE:=v1.9.9
	URL:=https://codeload.github.com/troydhanson/uthash/tar.gz/
endef
$(eval $(call Download,uthash))

define Package/$(PKG_NAME)/Default
	MAINTAINER:=Entware team, entware.wl500g.info
	SECTION:=utils
	CATEGORY:=Utilities
	URL:=http://luke.dashjr.org/programs/$(PKG_NAME)
	DEPENDS:=+$(PKG_NAME)
endef

define Package/$(PKG_NAME)
$(call Package/$(PKG_NAME)/Default)
	TITLE:=$(PKG_TITLE) (Bitcoin miner)
	DEPENDS:=+libevent2 +libcurl +libpthread +jansson +PACKAGE_$(PKG_NAME)_curses:libncurses +PACKAGE_$(PKG_NAME)_libusb:libusb-1.0
endef

define Package/$(PKG_NAME)/description
Modular Bitcoin CPU/GPU/FPGA miner in C
endef

define Package/$(PKG_NAME)/config
config PACKAGE_$(PKG_NAME)_curses
	bool "Build with curses TUI support"
	depends on PACKAGE_$(PKG_NAME)
	default y
config PACKAGE_$(PKG_NAME)_libusb
	bool "Build with libusb support (X6500 & ZTEX)"
	depends on PACKAGE_$(PKG_NAME)
	default y
endef

ifndef CONFIG_PACKAGE_$(PKG_NAME)_curses
CONFIGURE_ARGS += --without-curses
else
CONFIGURE_ARGS += --with-curses=ncurses
endif

ifndef CONFIG_PACKAGE_$(PKG_NAME)_libusb
CONFIGURE_ARGS += --disable-x6500 --disable-ztex
endif

TARGET_CFLAGS += -std=gnu99
TARGET_CFLAGS += -Iuthash-1.9.9/src

CONFIGURE_ARGS += --without-libudev
CONFIGURE_ARGS += --without-sensors

define Build/Prepare
	$(call Build/Prepare/Default)
	gzip -dc $(DL_DIR)/v1.9.9 | $(HOST_TAR) -C $(PKG_BUILD_DIR) $(TAR_OPTIONS)
endef

define Build/Configure
	# Need to remake configure etc to pick up on cross-compiler libtool
	( cd $(PKG_BUILD_DIR); NOSUBMODULES=1 ./autogen.sh; )
	
	$(call Build/Configure/Default)
endef

define Package/$(PKG_NAME)/install
	$(INSTALL_DIR) $(1)/opt/bin $(1)/opt/lib
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/$(PKG_NAME){,-rpc} $(1)/opt/bin
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/lib{blkmaker*,base58}.so* $(1)/opt/lib
endef

ALL_$(PKG_NAME)_PACKAGES += $(PKG_NAME)

$(foreach bitstream,$(ALL_$(PKG_NAME)_PACKAGES),$(eval $(call BuildPackage,$(bitstream))))
