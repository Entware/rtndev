# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2024 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=fake-hwclock
PKG_VERSION:=0.13
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)_$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=@DEBIAN/pool/main/f/fake-hwclock
PKG_HASH:=63c37d4befe388cfc65b30660403fff638692fc05fbf76d497340b4158747b11

include $(INCLUDE_DIR)/package.mk

PKG_UNPACK:=$(HOST_TAR) -C $(PKG_BUILD_DIR) --strip-components=1 -xf $(DL_DIR)/$(PKG_SOURCE)

define Package/fake-hwclock
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=loads/saves current kernel clock from/to file
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/fake-hwclock/description
 Trivial script to load/save current contents of the kernel clock
 from/to a file. Helpful as a *bootstrap* clock on machines where
 there isn't a useful RTC driver (e.g. on development boards). Using
 NTP is still recommended on these machines to get to real time sync
 once more of the system is up and running.
endef

define Build/Configure
endef

define Build/Compile
endef

define Package/fake-hwclock/install
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S01fake-hwclock $(1)/opt/etc/init.d
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/fake-hwclock $(1)/opt/bin
endef

define Package/fake-hwclock/postinst
#!/bin/sh

fake-hwclock
endef

$(eval $(call BuildPackage,fake-hwclock))
