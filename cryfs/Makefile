#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# XXX https://github.com/cryfs/cryfs/commit/ef4bc7aba2eeed728176b4ff5737d959cfcdc4d7

include $(TOPDIR)/rules.mk

PKG_NAME:=cryfs
PKG_VERSION:=0.10.3
PKG_REV:=0f83a1ab7e5ca9f37f97bc57b20d3fab0f351d11
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_REV).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/cryfs/cryfs.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=0c80c6e362844b895d55389ab2df197d0aa9474ffa0da943a1c3dfb7cd77a719

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/cryfs
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Filesystem
	DEPENDS:=+fuse-utils +libcurl +boost-program_options +boost-thread +boost-filesystem
	TITLE:=CryFS encrypts your files, so you can safely store them anywhere
	URL:=https://www.cryfs.org
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/cryfs/description
 CryFS encrypts your files, so you can safely store them anywhere. It works well
 together with cloud services like Dropbox, iCloud, OneDrive and others.
endef

CMAKE_OPTIONS += \
	-DBoost_USE_STATIC_LIBS=OFF \
	-DDISABLE_OPENMP=ON

define Package/cryfs/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/cryfs $(1)/opt/bin
endef

$(eval $(call BuildPackage,cryfs))
