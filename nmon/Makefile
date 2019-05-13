#
# Copyright (C) 2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=nmon
PKG_VERSION:=16j
PKG_RELEASE:=1

PKG_SOURCE:=lmon$(PKG_VERSION).c
PKG_SOURCE_URL:=@SF/nmon
PKG_HASH:=ba3878c9b3e3bbb1635659735e8373624ba938904889f130183908c203f34615

PKG_MAINTAINER:=Thomas Kupper <thomas.kupper@gmail.com>
PKG_LICENSE:=GPL-2.0
PKG_LICENSE_FILES:=LICENSE-GPL2

UNPACK_CMD=$(CP) $(DL_DIR)/$(PKG_SOURCE) $(1)

include $(INCLUDE_DIR)/package.mk

define Package/nmon
	SECTION:=nmon
	CATEGORY:=Administration
	URL:=http://nmon.sourceforge.net/pmwiki.php
	TITLE:=Nigel's performance Monitor for Linux
	DEPENDS:=+libncurses
endef

define Package/nmon/description
 Linux performance monitoring on-screen or to CSV file.
endef

TARGET_LDFLAGS += -lncurses -lm -g
TARGET_CPPFLAGS += -g -O3 -Wall -D JFS -D GETUSER -D LARGEMEM

define Build/Compile
	$(TARGET_CC) $(TARGET_CPPFLAGS) $(TARGET_CFLAGS) -o $(PKG_BUILD_DIR)/$(PKG_NAME) \
		$(PKG_BUILD_DIR)/$(MAKE_PATH)/$(PKG_SOURCE) $(TARGET_LDFLAGS)
endef

define Package/nmon/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(CP) $(PKG_BUILD_DIR)/$(PKG_NAME) $(1)/opt/bin/
endef

$(eval $(call BuildPackage,nmon))
