# PDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=fatrace
PKG_VERSION:=0.19.1
PKG_REV:=62bd8e6d7ad7f112b37a8d5fe3dbb88c13b34844
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/martinpitt/fatrace.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=f1c27b39973294f5136e0a4c313419a4e6c7af3ec911e831db9ff2ce901aba88

include $(INCLUDE_DIR)/package.mk

define Package/fatrace
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=@!LINUX_2_6_36
	TITLE:=fatrace reports file access events from all running processes
	URL:=https://piware.de/2012/02/fatrace-report-system-wide-file-access-events/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/fatrace/description
 Its main purpose is to find processes which keep waking up the disk unnecessarily
 and thus prevent some power saving.
endef

define Build/Compile
	$(TARGET_CC) $(TARGET_CFLAGS) -c $(TARGET_CPPFLAGS) -o $(PKG_BUILD_DIR)/$(PKG_NAME).o $(PKG_BUILD_DIR)/$(PKG_NAME).c
	$(TARGET_CC) $(TARGET_LDFLAGS) -L$(STAGING_DIR)/opt/lib -o $(PKG_BUILD_DIR)/$(PKG_NAME) $(PKG_BUILD_DIR)/$(PKG_NAME).o
endef

define Package/fatrace/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/fatrace $(1)/opt/bin
endef

$(eval $(call BuildPackage,fatrace))
