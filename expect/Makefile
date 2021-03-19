#
# Copyright (C) 2020-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=expect
PKG_VERSION:=5.45.4
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/expect
PKG_HASH:=49a7da83b0bdd9f46d04a04deec19c7767bb9a323e40c4781f89caf760b92c34

PKG_FIXUP:=autoreconf
PKG_REMOVE_FILES:=testsuite/configure.in
PKG_INSTALL:=1

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/expect
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+tcl
	TITLE:=Expect
	URL:=https://www.nist.gov/services-resources/software/expect
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/expect/description
 Expect is a tool for automating interactive applications such as telnet, ftp,
 etc. Expect can make easy all sorts of tasks that are prohibitively
 difficult with anything else.
endef

CONFIGURE_ARGS += \
	--with-tcl=$(STAGING_DIR)/opt/lib

MAKE_FLAGS += \
	RANLIB=":"

define Package/expect/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/expect* $(1)/opt/bin

	$(INSTALL_DIR) $(1)/opt/lib/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/$(PKG_NAME)$(PKG_VERSION) $(1)/opt/lib
endef

$(eval $(call BuildPackage,expect))
