#
# Copyright (C) 2016 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=tree
PKG_VERSION:=1.7.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tgz
PKG_SOURCE_URL:=ftp://mama.indstate.edu/linux/tree
PKG_MD5SUM:=abe3e03e469c542d8e157cdd93f4d8a6

include $(INCLUDE_DIR)/package.mk

define Package/tree
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=recursive directory listing
	URL:=http://mama.indstate.edu/users/ice/tree/
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/tree/description
 Tree is a recursive directory listing command that produces a depth indented
 listing of files, which is colorized ala dircolors.
endef

define Package/tree/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(CP) $(PKG_BUILD_DIR)/tree $(1)/opt/bin
endef

$(eval $(call BuildPackage,tree))
