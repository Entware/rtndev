#
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=fatrace
PKG_VERSION:=0.16.2
PKG_REV:=5207e325aa59d6e54dcda4f3336d92648ff89507
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=git://git.launchpad.net/fatrace
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

define Package/fatrace
	SECTION:=utils
	CATEGORY:=Utilities
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
