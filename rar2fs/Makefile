#
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=rar2fs
PKG_VERSION:=1.29.2
PKG_REV:=2c47c3a285bc7b65933c865d546459d4c5f9b4b2
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/hasse69/rar2fs.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/rar2fs
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Filesystem
	DEPENDS:=+libfuse +libunrar +librt $(ICONV_DEPENDS)
	TITLE:=FUSE file system for reading RAR archives
	URL:=https://github.com/hasse69/rar2fs
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/rar2fs/description
 FUSE file system for reading RAR archives.
endef

define Build/Prepare
	$(call Build/Prepare/Default)
	mkdir $(PKG_BUILD_DIR)/config
	$(LN) $(PKG_BUILD_DIR)/config.rpath $(PKG_BUILD_DIR)/config/config.rpath
endef

CONFIGURE_ARGS += \
	--with-unrar=$(STAGING_DIR)/opt/include/unrar \
	--with-libiconv-prefix=$(ICONV_PREFIX) \
	--enable-static-unrar=no

define Package/rar2fs/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/{mkr2i,rar2fs} $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/sbin
	$(LN) /opt/bin/rar2fs $(1)/opt/sbin/mount.rar2fs
endef

$(eval $(call BuildPackage,rar2fs))
