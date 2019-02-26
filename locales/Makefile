#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=locales
PKG_RELEASE:=8
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_RELEASE)

include $(INCLUDE_DIR)/package.mk

define Package/locales
	SECTION:=libs
	CATEGORY:=Base system
	URL:=http://gcc.gnu.org/
	TITLE:=Locales support (independent of system lib)
	VERSION:=$(LIBC_VERSION)-$(PKG_RELEASE)
	DEPENDS:=+grep @USE_GLIBC
endef

LVERSION1:=$(call qstrip,$(CONFIG_GLIBC_VERSION))
LVERSION2:=$(subst .,,$(LVERSION1))

define Package/locales/preinst
#!/bin/sh

if [[ -x "/opt/bin/locale.new" ]]; then
	/opt/bin/locale.new -V | grep $(LVERSION1) > /dev/null
	if [ $$? -ne 0 ] ; then
		echo "Deleting locale-archive. It needs upgrade."
		rm -f /opt/usr/lib/locale/locale-archive
	fi
fi

endef


define Package/locales/postinst
#!/bin/sh

echo "Entware uses separate locale-archive file independent from main system"
if ! [ -f '/opt/usr/lib/locale/locale-archive' ]
then
	mkdir -p /opt/usr/lib/locale
	echo "Creating locale archive - /opt/usr/lib/locale/locale-archive"
	echo "Adding en_EN.UTF-8"
	/opt/bin/localedef.new -c -f UTF-8 -i en_US en_US.UTF-8
	echo "Adding ru_RU.UTF-8"
	/opt/bin/localedef.new -c -f UTF-8 -i ru_RU ru_RU.UTF-8
fi
if [ -f '/opt/usr/lib/locale/locale-archive' ]
then
	echo "You can download locale sources from http://pkg.entware.net/sources/i18n_glib$(LVERSION2).tar.gz"
	echo "You can add new locales to Entware using /opt/bin/localedef.new"
fi
if ! [ -f '/opt/usr/lib/locale/locale-archive' ]
then
	echo "locale-archive file was not created, not enough memory? Downloading..."
	echo "checking endianess...."
	/opt/bin/islebe
	if [ $$? == 0 ]; then
		echo "BE detected"
		be='.be'
	fi
	wget http://pkg.entware.net/binaries/other/locale-archive.$(LVERSION1)$$be -O /opt/usr/lib/locale/locale-archive
	echo "You can download locale sources from http://pkg.entware.net/sources/i18n_glib$(LVERSION2).tar.gz"
	echo "You can add new locales to Entware using /opt/bin/localedef.new"
fi

endef

define Build/Configure
endef

define Build/Compile
	$(TARGET_CC) $(TARGET_CFLAGS) -I$(STAGING_DIR)/opt/include \
		$(TARGET_LDFLAGS) -L$(STAGING_DIR)/opt/lib -o $(PKG_BUILD_DIR)/islebe \
		$(PKG_BUILD_DIR)/test_le_be.c
endef

ilocales=de_DE en_US en_GB fr_FR it_IT ru_RU i18n \
	$(if $(CONFIG_GLIBC_USE_VERSION_2_27),i18n_ctype,) \
	iso14651_t1 iso14651_t1_common \
	translit_circle translit_combining translit_font translit_narrow translit_small \
	translit_cjk_compat translit_compat translit_fraction translit_neutral translit_wide

icharmaps=ANSI_X3.4-1968.gz UTF-8.gz


define Package/locales/install
	$(INSTALL_DIR) $(1)/opt/usr/lib/locale
	$(INSTALL_DIR) $(1)/opt/usr/share/i18n/locales
	$(INSTALL_DIR) $(1)/opt/usr/share/i18n/charmaps
	$(INSTALL_DIR) $(1)/opt/bin
	$(CP) $(TOOLCHAIN_DIR)/bin/locale $(1)/opt/bin/locale.new
	$(CP) $(TOOLCHAIN_DIR)/bin/localedef $(1)/opt/bin/localedef.new
	$(CP) $(PKG_BUILD_DIR)/islebe $(1)/opt/bin
	for file in $(ilocales); do \
		$(CP) $(TOOLCHAIN_DIR)/share/i18n/locales/$$$$file $(1)/opt/usr/share/i18n/locales ; \
	done ; \
	for file in $(icharmaps); do \
		$(CP) $(TOOLCHAIN_DIR)/share/i18n/charmaps/$$$$file $(1)/opt/usr/share/i18n/charmaps ; \
	done ; \
	exit 0
endef

$(eval $(call BuildPackage,locales))
