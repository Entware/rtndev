#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2010

include $(TOPDIR)/rules.mk

PKG_NAME:=fuse-convmvfs
PKG_VERSION:=0.2.6
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/fuse-convmvfs
PKG_HASH:=67566fd4bc3f66211156872c60164aca898dcbba0669d52b8f74a9911b789695

PKG_FIXUP:=libtool
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/fuse-convmvfs
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Filesystem
	DEPENDS:=$(ICONV_DEPENDS) +libfuse +libstdcpp
	TITLE:=mirrors a whole filesystem tree from one charset to another
	URL:=http://fuse-convmvfs.sourceforge.net/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/fuse-convmvfs/description
 This is a filesystem converting file name from one character set to another. It's implemented by using FUSE.
endef

EXTRA_CXXFLAGS += \
	-I$(ICONV_PREFIX)/include \
	-I$(STAGING_DIR)/opt/include/fuse \
	-DICONV_CONST=const \

EXTRA_LDFLAGS += \
	-L$(INTL_PREFIX)/lib \
	-L$(ICONV_PREFIX)/lib \
	-liconv \
	-lpthread \

define Package/fuse-convmvfs/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/convmvfs $(1)/opt/bin/
endef

$(eval $(call BuildPackage,fuse-convmvfs))
