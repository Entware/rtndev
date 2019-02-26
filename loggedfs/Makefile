#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=loggedfs
PKG_VERSION:=0.9
PKG_RELEASE:=1


PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).zip
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/rflament/loggedfs/archive
PKG_HASH:=49b19ebed4dc4283737f602121ee79505b57b7577445e2c2f6121a7b4a1897d5

include $(INCLUDE_DIR)/package.mk

define Package/loggedfs
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Filesystem
	DEPENDS:=+fuse-utils +libstdcpp +libxml2 +libpcre
	TITLE:=Filesystem monitoring with Fuse
	URL:=https://www.loggedfs.org
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/loggedfs/description
 LoggedFS is a fuse-based filesystem which can log every operations that happens in it
endef

define Package/loggedfs/install
	$(INSTALL_DIR) $(1)/opt/bin $(1)/opt/etc
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/loggedfs $(1)/opt/bin
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/loggedfs.xml $(1)/opt/etc
endef

$(eval $(call BuildPackage,loggedfs))
