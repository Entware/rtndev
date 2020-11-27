#
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=bindfs
PKG_VERSION:=1.14.8
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://bindfs.org/downloads
PKG_HASH:=e5ca5aff55204b993a025a77c3f8c0e2ee901ba8059d71bea11de2cc685ec497

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/bindfs
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Filesystem
	DEPENDS:=+fuse-utils +librt
	TITLE:=bindfs filesystem
	URL:=http://bindfs.org
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/bindfs/description
 bindfs - mount a directory to another location and alter permission bits.
endef

TARGET_CFLAGS += -I$(STAGING_DIR)/opt/include/fuse

define Package/bindfs/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/* $(1)/opt/bin
endef

$(eval $(call BuildPackage,bindfs))
