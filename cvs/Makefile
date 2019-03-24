#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2008

include $(TOPDIR)/rules.mk

PKG_NAME:=cvs
PKG_VERSION:=1.11.23
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=https://ftp.gnu.org/non-gnu/cvs/source/stable/1.11.23
PKG_HASH:=400f51b59d85116e79b844f2d5dbbad4759442a789b401a94aa5052c3d7a4aa9

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/cvs
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Version Control Systems
	TITLE:=CVS is a version control system
	URL:=http://savannah.nongnu.org/projects/cvs/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/cvs/description
 CVS is a version control system, an important component of Source Configuration Management (SCM). 
 Using it, you can record the history of sources files, and documents.
 It fills a similar role to the free software RCS, PRCS, and Aegis packages. 
endef

CONFIGURE_ARGS += --without-gssapi

define Package/cvs/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/* $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/share/cvs/contrib
	$(CP) $(PKG_INSTALL_DIR)/opt/share/cvs/contrib/* $(1)/opt/share/cvs/contrib
	$(SED) 's,$(STAGING_DIR_HOST)/bin/perl,/opt/bin/perl,g' $(1)/opt/share/cvs/contrib/*
endef

$(eval $(call BuildPackage,cvs))
