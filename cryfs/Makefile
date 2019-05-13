#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=cryfs
PKG_VERSION:=0.10.1
PKG_REV:=e732cc03f6e374455f0c3e7c2ec82d1f2d99acdb
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/cryfs/cryfs.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/cryfs
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Filesystem
	DEPENDS:=+fuse-utils +libcryptoxx +libcurl +boost-program_options +boost-thread +boost-filesystem +boost-date_time
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
