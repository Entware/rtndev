#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=s3fs-fuse
PKG_VERSION:=1.93
PKG_REV:=5371cd1468c84423729c334ac997f9621b797e9f
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/s3fs-fuse/s3fs-fuse.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=cc2297e27d3d413f46d4f6d3099962a8941353f9209c572ddf8d675014c1ed13

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/s3fs-fuse
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Filesystem
	DEPENDS:=+libfuse +libcurl +libxml2 +libstdcpp
	TITLE:=FUSE filesystem for Amazon S3
	URL:=https://github.com/s3fs-fuse/s3fs-fuse
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/s3fs-fuse/description
 FUSE-based file system backed by Amazon S3.
endef

CONFIGURE_ARGS += \
	--with-openssl

define Package/s3fs-fuse/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/s3fs $(1)/opt/bin
endef

$(eval $(call BuildPackage,s3fs-fuse))
