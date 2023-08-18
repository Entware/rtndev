#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# 0.11.0 requires host Conan, Cryptopp library bumped to 8.5.0,
# so few additional runtime tests required.

include $(TOPDIR)/rules.mk

PKG_NAME:=cryfs
PKG_VERSION:=0.10.4
PKG_REV:=2514e123d27dc3175ccbfeebe68ecee0b6cb897a
PKG_RELEASE:=4

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/cryfs/cryfs.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=39f4565bdbe1cbdbf4650818173312a4f2f1239aa1bd6117f1cd27e58e64acc6

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
