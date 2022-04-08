#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=s3fs-fuse
PKG_VERSION:=1.91
PKG_REV:=49d92c70221be93c82c9462343721959dc0fdc56
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/s3fs-fuse/s3fs-fuse.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=c3d565f030a32c8b532e700feed4fd23846e17b2e4df773cff5ceff7a5a9c1f5

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
