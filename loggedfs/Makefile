#
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=loggedfs
PKG_VERSION:=0.9
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/rflament/loggedfs/archive
PKG_HASH:=10cd007782c6b91a154758dabac0c3b41e580ca0f9496cab411054219ef52b22

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

PKG_UNPACK:=$(HOST_TAR) -C $(PKG_BUILD_DIR) --strip-components=1 -xzf $(DL_DIR)/$(PKG_SOURCE)

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
