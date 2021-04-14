#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=simple-mtpfs
PKG_VERSION:=0.4.0
PKG_REV:=19e7bb9b608b0c0dce2ee6f56fac75901bc69529
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/phatina/simple-mtpfs.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=ebea7984a6daf1fe37eea32a2f6f3f8877d66d4a9d66126443ef3e81173af33f

PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/simple-mtpfs
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Filesystem
	DEPENDS:=+libmtp +libfuse +libstdcpp
	TITLE:=MTP fuse filesystem driver
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/simple-mtpfs/description
 SIMPLE-MTPFS (Simple Media Transfer Protocol FileSystem) is a file system
 capable of operating on files on MTP devices attached via USB to local machine.
 The practical effect of this is that the end user can seamlessly interact
 with MTP device files.
endef

CONFIGURE_ARGS += \
	--with-tmpdir=/opt/tmp

TARGET_CPPFLAGS += \
	-I$(STAGING_DIR)/opt/include/fuse

define Package/simple-mtpfs/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/simple-mtpfs $(1)/opt/bin
endef

$(eval $(call BuildPackage,simple-mtpfs))
