#
# Copyright (C) 2011-2017 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=inotify-tools
PKG_VERSION:=3.14
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/downloads/rvoicilas/inotify-tools
PKG_MD5SUM:=b43d95a0fa8c45f8bab3aec9672cf30c

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/inotify-tools
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Filesystem
	TITLE:=package of some commandline utilities relating to inotify
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/inotify-tools/description
 This is a package of some commandline utilities relating to inotify. The general purpose
 of this package is to allow inotify's features to be used from within shell scripts.
endef

define Package/inotify-tools/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/inotify{wait,watch} $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libinotifytools.so* $(1)/opt/lib
endef

$(eval $(call BuildPackage,inotify-tools))
