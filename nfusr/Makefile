#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=nfusr
PKG_VERSION:=1.0.0-20190319
PKG_REV:=4c21b69f201b50b8f1dd3aac0125baa3b5d02ade
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/facebookincubator/nfusr
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/nfusr
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Filesystem
	DEPENDS:=+libstdcpp +fuse-utils +libnfs $(ICONV_DEPENDS) $(INTL_DEPENDS)
	TITLE:=a userspace FUSE client for accessing NFSv3 servers
	URL:=https://github.com/facebookincubator/nfusr
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/nfusr/description
 nfusr is a userspace FUSE client for accessing NFSv3 servers based on libnfs.
endef

TARGET_CPPFLAGS += -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -D_GNU_SOURCE

define Package/nfusr/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/$(PKG_NAME) $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/sbin/mount.$(PKG_NAME) $(1)/opt/sbin
endef

$(eval $(call BuildPackage,nfusr))
