# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2024 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=bindfs
PKG_VERSION:=1.17.6
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://bindfs.org/downloads
PKG_HASH:=d3beb3cc69bb2b6802cc539588e921fea973ed6191b133f2024719311d1cc18b

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/bindfs
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Filesystem
	DEPENDS:=+fuse3-utils +librt
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
