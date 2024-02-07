# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2019-2024 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=nmon
PKG_VERSION:=16p
PKG_RELEASE:=1

PKG_SOURCE:=lmon$(PKG_VERSION).c
PKG_SOURCE_URL:=@SF/nmon
PKG_HASH:=5dc6045f6725e3249a969918fae69663a1d669162087720babcdb90fce9e6b2a

PKG_MAINTAINER:=Thomas Kupper <thomas.kupper@gmail.com>
PKG_LICENSE:=GPL-2.0
PKG_LICENSE_FILES:=LICENSE-GPL2

UNPACK_CMD=$(CP) $(DL_DIR)/$(PKG_SOURCE) $(1)

include $(INCLUDE_DIR)/package.mk

define Package/nmon
	SECTION:=nmon
	CATEGORY:=Administration
	DEPENDS:=+libncurses
	TITLE:=Nigel's performance Monitor for Linux
	URL:=http://nmon.sourceforge.net/pmwiki.php
endef

define Package/nmon/description
 Linux performance monitoring on-screen or to CSV file.
endef

TARGET_LDFLAGS += -lncurses -lm -g
TARGET_CFLAGS += -g -O3 -Wall -D JFS -D GETUSER -D LARGEMEM

define Build/Compile
	$(TARGET_CC) $(TARGET_CPPFLAGS) $(TARGET_CFLAGS) -o $(PKG_BUILD_DIR)/$(PKG_NAME) \
		$(PKG_BUILD_DIR)/$(MAKE_PATH)/$(PKG_SOURCE) $(TARGET_LDFLAGS)
endef

define Package/nmon/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(CP) $(PKG_BUILD_DIR)/$(PKG_NAME) $(1)/opt/bin
endef

$(eval $(call BuildPackage,nmon))
