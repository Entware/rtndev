# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2025 Entware
#

include $(TOPDIR)/rules.mk

PKG_NAME:=s3fs-fuse
PKG_VERSION:=1.95
PKG_REV:=561ce1e20600bab42133b5e51511483800d3ef76
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/s3fs-fuse/s3fs-fuse.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=b2f392ddcac830bd20abf01d67ba9641b4b2e0cdf6cff96a1344aa686634ef5c

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
