#
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# based on Makefile from https://github.com/MarvAmBass/lede-gnupg2.git

include $(TOPDIR)/rules.mk

PKG_NAME:=libksba
PKG_VERSION:=1.4.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=https://www.gnupg.org/ftp/gcrypt/libksba/
PKG_HASH:=bfe6a8e91ff0f54d8a329514db406667000cb207238eded49b599761bfca41b6

PKG_LICENSE:=GPL-3.0
PKG_LICENSE_FILES:=COPYING

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/libksba
	SECTION:=libs
	CATEGORY:=Libraries
	DEPENDS:=+libgpg-error
	TITLE:=provides an easy API to create and parse X.509 and CMS related objects
	URL:=http://www.gnupg.org/
endef

define Package/libksba/description
 Libksba is a library to make the tasks of working with X.509 certificates,
 CMS data and related objects more easy. It provides a highlevel interface
 to the implemented protocols and presents the data in a consistent way.
 There is no more need to worry about all the nasty details of the protocols.
 The API gives the C programmer an easy way of interacting with the data.
 It copes with the version details X.509 protocols tend to have as well as with
 the many different versions and dialects.Applications must usually cope with
 all of this and it has to be coded over and over again. Libksba hides this
 by providing just one API which does the Right Thing. Support for new features
 will be added as needed.
endef

TARGET_CFLAGS += $(FPIC)

CONFIGURE_ARGS += --enable-shared --enable-static

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/bin $(2)/bin $(1)/opt/include $(1)/opt/lib $(1)/opt/share/aclocal
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/ksba-config $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/include/ksba*.h $(1)/opt/include/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libksba.{la,a,so*} $(1)/opt/lib/
	$(CP) $(PKG_INSTALL_DIR)/opt/share/aclocal/ksba.m4 $(1)/opt/share/aclocal/
	$(SED) 's,^\(prefix\|exec_prefix\)=.*,\1=$(STAGING_DIR)/opt,g' $(1)/opt/bin/ksba-config
	ln -sf $(STAGING_DIR)/opt/bin/ksba-config $(2)/bin/
endef

define Package/libksba/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libksba.so.* $(1)/opt/lib/
endef

$(eval $(call BuildPackage,libksba))
