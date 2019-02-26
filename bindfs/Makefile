#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=bindfs
PKG_VERSION:=1.13.10
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://bindfs.org/downloads
PKG_HASH:=92b8c1c124f1629fe1a8aca4a1268a4bc67b26496e6e8ceb0d0e54c99ab88e93

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)
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
  bindfs - mount a directory to another location and alter permission bits
endef

TARGET_CFLAGS += -I$(STAGING_DIR)/opt/include/fuse \

define Package/bindfs/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/* $(1)/opt/bin
endef

$(eval $(call BuildPackage,bindfs))
