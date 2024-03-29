# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2024 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=aspell
PKG_VERSION:=0.60.8.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@GNU/$(PKG_NAME)
PKG_HASH:=d6da12b34d42d457fa604e435ad484a74b2effcd120ff40acd6bb3fb2887d21b

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/aspell
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+libncursesw +libaspell
	TITLE:=spell checker
	URL:=http://aspell.net/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/libaspell
	SECTION:=libs
	CATEGORY:=Libraries
	DEPENDS:=+libstdcpp
	TITLE:=spell checker library
	URL:=http://aspell.net/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/aspell/description
 GNU Aspell does a superior job of suggesting possible replacements for
 a misspelled word than just about any other spell checker out there for
 the English (and some other) language.
endef

define Package/libaspell/description
 GNU Aspell library
endef

CONFIGURE_ARGS += \
	--disable-static \
	--program-transform-name='' \

TARGET_CFLAGS+=-fpermissive

define Package/aspell/postinst
#!/bin/sh

echo -e "\n#####Available dictionaries at ftp://ftp.gnu.org/gnu/aspell/dict/0index.html \n\
Sample English dictionary install for aspell: \n\
     cd /opt/tmp \n\
     opkg install make \n\
     wget https://ftp.gnu.org/gnu/aspell/dict/en/aspell6-en-2019.10.06-0.tar.bz2 \n\
     tar xvjf aspell6-en-2019.10.06-0.tar.bz2 \n\
     cd aspell6-en-2019.10.06-0 \n\
     ./configure \n\
     make \n\
     make install \n\
     Note that some dictionaries require lot of memory for word compression."
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/include/* $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/lib{p,a}spell.so* $(1)/opt/lib
endef

define Package/aspell/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/* $(1)/opt/bin
	$(SED) 's,/usr/bin/perl,/opt/bin/perl,g' $(1)/opt/bin/aspell-import
	$(INSTALL_DIR) $(1)/opt/etc
	$(CP) ./files/aspell.conf $(1)/opt/etc
endef

define Package/libaspell/install
	$(INSTALL_DIR) $(1)/opt/lib/aspell-0.60
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/lib{p,a}spell.so* $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/aspell-0.60/* $(1)/opt/lib/aspell-0.60
endef

$(eval $(call BuildPackage,aspell))
$(eval $(call BuildPackage,libaspell))
