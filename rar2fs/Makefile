#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=rar2fs
PKG_VERSION:=1.27.2
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/hasse69/rar2fs/releases/download/v$(PKG_VERSION)
PKG_HASH:=c572847dedcf7b5e2b7a7067a1040f1de616ef08

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
	$(LN) $(PKG_BUILD_DIR)/config.rpath $(PKG_BUILD_DIR)/config/config.rpath
endef

CONFIGURE_ARGS += \
	--with-unrar=$(STAGING_DIR)/opt/include/unrar \
	--with-libiconv-prefix=$(ICONV_PREFIX) \
	--enable-static-unrar=no \

define Package/rar2fs/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/{mkr2i,rar2fs} $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/sbin
	$(LN) /opt/bin/rar2fs $(1)/opt/sbin/mount.rar2fs
endef

$(eval $(call BuildPackage,rar2fs))
