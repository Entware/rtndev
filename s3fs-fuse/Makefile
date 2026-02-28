# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2026 Entware
#

include $(TOPDIR)/rules.mk

PKG_NAME:=s3fs-fuse
PKG_VERSION:=1.97
PKG_REV:=0d96734dade0546a949932b56cdb5c8dd5f54e9b
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/s3fs-fuse/s3fs-fuse.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=f156465e5f79f1c12e133f34a352de086581506c6813653691b539da331c3824

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/s3fs-fuse
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Filesystem
	DEPENDS:=+libfuse3 +libcurl +libxml2 +libstdcpp
	TITLE:=FUSE filesystem for Amazon S3
	URL:=https://github.com/s3fs-fuse/s3fs-fuse
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/s3fs-fuse/description
 FUSE-based file system backed by Amazon S3.
endef

CONFIGURE_ARGS += \
	--with-openssl

ifeq ($(or $(CONFIG_mips),$(CONFIG_mipsel)),y)
  TARGET_LDFLAGS += -latomic
endif

define Package/s3fs-fuse/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/s3fs $(1)/opt/bin
endef

$(eval $(call BuildPackage,s3fs-fuse))
